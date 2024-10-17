module o  
implicit none 
	integer, parameter :: dms=3 ! number of unknowns
	real (kind = 8), dimension(dms) :: x=(/1d0, 2d0, 3d0/) ! initial condition
	real (kind = 8) :: t=0d0,te=1200d0 ! beginning and ending time points
	real (kind = 8) :: d=real(dms)
contains      
	subroutine f(t,y,f0)
		implicit none
		real (kind = 8), intent(in) :: t
		real (kind = 8), dimension(dms), intent(in) :: y
		real (kind = 8), dimension(dms), intent(out) :: f0
		
		f0(1)=77.27d0*(y(2)+y(1)*(1-8.375d-6*y(1)-y(2)))
		f0(2)=(y(3)-(1+y(1))*y(2))/77.27d0
		f0(3)=0.161d0*(y(1)-y(3))
	end subroutine f
end module o 
