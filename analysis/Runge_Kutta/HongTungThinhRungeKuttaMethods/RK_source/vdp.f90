module vdp  
implicit none 
	integer, parameter :: dms=2 ! number of unknowns
	real (kind = 8), dimension(dms) :: x=(/2d0, -0.66d0/) ! initial condition
	real (kind = 8) :: t=0d0,te=2d0 ! beginning and ending time points
	real (kind = 8) :: d=real(dms)
contains      
	subroutine f(t,y,f0)
		implicit none
		real (kind = 8), intent(in) :: t
		real (kind = 8), dimension(dms), intent(in) :: y
		real (kind = 8), dimension(dms), intent(out) :: f0
		
		f0(1)=y(2)
		f0(2)=(((1-(y(1)**2))*y(2))-y(1))*1d+6
	end subroutine f
end module vdp 
