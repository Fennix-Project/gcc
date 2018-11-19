! { dg-do run }
! { dg-skip-if "" { *-*-* } { "*" } { "-DACC_MEM_SHARED=0" } }

program main
  use openacc
  implicit none

  integer, parameter :: N = 256
  integer, allocatable :: h(:)
  integer :: i
  integer :: async = 5

  allocate (h(N))

  do i = 1, N
    h(i) = i
  end do 

  call acc_copyin (h)

  do i = 1, N
    h(i) = i + i
  end do 

  call acc_update_device_async (h, sizeof (h), async)

  if (acc_is_present (h) .neqv. .TRUE.) call abort

  h(:) = 0

  call acc_copyout_async (h, sizeof (h), async)

  call acc_wait (async)

  do i = 1, N
    if (h(i) /= i + i) call abort
  end do 

  call acc_copyin (h, sizeof (h))

  h(:) = 0

  call acc_update_self_async (h, sizeof (h), async)
  
  if (acc_is_present (h) .neqv. .TRUE.) call abort

  do i = 1, N
    if (h(i) /= i + i) call abort
  end do 

  call acc_delete_async (h, async)

  call acc_wait (async)

  if (acc_is_present (h) .neqv. .FALSE.) call abort
  
end program
