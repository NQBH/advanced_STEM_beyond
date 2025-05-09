module bz2  
implicit none 
	integer, parameter :: dms=2 ! number of unknowns
	real (kind = 8), dimension(dms) :: x=(/1d-5, 1d-5/) ! initial condition
	real (kind = 8) :: t=0d0,te=40d0 ! beginning and ending time points
	real (kind = 8) :: d=real(dms)
contains      
	subroutine f(t,y,f0)
		implicit none
		real (kind = 8), intent(in) :: t
		real (kind = 8), dimension(dms), intent(in) :: y
		real (kind = 8), dimension(dms), intent(out) :: f0
		
		f0(1)=(y(1)*(1-y(1))+2/3d0*y(2)*(8d-4-y(1))/(8d-4+y(1)))*0.25d+2
		f0(2)=y(1)-y(2)
	end subroutine f
end module bz2
