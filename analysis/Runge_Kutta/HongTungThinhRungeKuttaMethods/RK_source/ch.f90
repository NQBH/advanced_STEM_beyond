module ch  
implicit none 
	integer, parameter :: dms=1 ! number of unknowns
	real (kind = 8), dimension(dms) :: x=(/1d0/) ! initial condition
	real (kind = 8) :: t=0d0,te=40d0 ! beginning and ending time points
	real (kind = 8) :: d=real(dms)
contains      
	subroutine f(t,y,f0)
		implicit none
		real (kind = 8), intent(in) :: t
		real (kind = 8), dimension(dms), intent(in) :: y
		real (kind = 8), dimension(dms), intent(out) :: f0
		
		f0(1)=-50*(y(1)-cos(t))
	end subroutine f
end module ch 
