module customf
implicit none 
	integer, parameter :: dms=3 ! number of unknowns
	real (kind = 8), dimension(dms) :: x=(/6d0, -1d0, -1d0/) ! initial condition
	real (kind = 8) :: t=0d0,te=40d0 ! begining time and ending time
	real (kind = 8) :: d=real(dms)
contains      
	subroutine f(t,y,f0)
		implicit none
		real (kind = 8), intent(in) :: t
		real (kind = 8), dimension(dms), intent(in) :: y
		real (kind = 8), dimension(dms), intent(out) :: f0
		
		f0(1)=y(2)
		f0(2)=y(3)
		f0(3)=6*y(1)-y(2)-y(3)
	end subroutine f
end module customf
