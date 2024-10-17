program rkfts
	use vdp ! module for systems of ODEs
	implicit none
	real (kind = 8) :: h=1d-2 ! time step
	real (kind = 8) :: start,finish
	integer :: i,j=1,p=1,v1,v2,inputerror
	real (kind = 8), dimension(dms) :: r
	real (kind = 8), dimension(4,4) :: a
	real (kind = 8), dimension(4) :: b,c

	call cpu_time(start)
	a=reshape((/0d0,0d0,0d0,0d0,&
		1/2d0,0d0,0d0,0d0,&
		0d0,1/2d0,0d0,0d0,&
		0d0,0d0,1d0,0d0/)&
		,shape(a),order=(/2,1/))
	b=(/1/6d0,1/6d0,2/3d0,0d0/)
	c=(/0d0,1/2d0,1/2d0,1d0/)

	open(unit=1,file="data.txt",form="formatted",status="replace",action="write")
	do while (t<=te)
		write(1,*) t,(x(i), i=1,dms)
		call rk(a,b,c,h,t,x,r)
		x=x+r
		t=t+h
	end do
	!write(1,*) t,(x(i), i=1,dms)
	close(unit=1)
	call cpu_time(finish)
	write(*,*) 'Finished',finish-start

	open(unit=2,file="para1.plt",form="formatted",status='replace',action="write")
		write(2,"(a,i0)") "d=",dms
		write(2,"(a,i0)") "p=",p
	close(unit=2)
	call system('gnuplot data_plot.plt')
	
	if (dms>=2) then
		do while (j/=0)
			write(*,*) 'Do you want to plot the dependency of 2 solutions ?'
			write(*,*) 'Enter 1 for "Yes" and 0 for "No".'
			read (*,"(i10)",iostat=inputerror) j
			if (j/=0 .and. j/=1 .or. inputerror/=0) then
				write(*,*) 'Invalid input ! Input must be either 1 or 0'
				cycle
			end if
			if (j==1) then
				write(*,*) 'Which of the 2 solutions you want to plot dependency ?'
				write(*,"(a,i0,a)") 'Enter the integer corresponding to the first solution (from 1 to ',dms,') to plot dependency'
				read (*,"(i10)",iostat=inputerror) v1
				if (v1<1 .or. v1>dms .or. inputerror/=0) then
					write(*,"(a,i0,a)") 'Invalid input ! Input must be a integer from 1 to ',dms,'.'
					cycle
				end if
				write(*,"(a,i0,a)") 'Enter the integer corresponding to the second solution (from 1 to ',dms,') to plot dependency'
				read (*,"(i10)",iostat=inputerror) v2
				if (v2<1 .or. v2>dms .or. inputerror/=0) then
					write(*,"(a,i0,a)") 'Invalid input ! Input must be a integer from 1 to ',dms,'.'
					cycle
				else if (v2==v1) then
					write(*,*) 'Invalid input ! The second input must be a different from the first input.'
					cycle
				end if
				open(unit=3,file="para2.plt",form="formatted",status='replace',action="write")
					write(3,"(a,i0)") "v1=",v1
					write(3,"(a,i0)") "v2=",v2
				close(unit=3)
				call system('gnuplot data_plot_dependency.plt')
			end if
		end do
	end if

contains
	subroutine rk(a,b,c,h,t,x,r)
		implicit none
		real (kind = 8), intent(in) :: t,h
		real (kind = 8), dimension(dms), intent(in) :: x
		real (kind = 8), dimension(4,4), intent(in) :: a
		real (kind = 8), dimension(4), intent(in) :: b, c
		real (kind = 8), dimension(dms), intent(out) :: r
		real (kind = 8), dimension(dms) :: k1,k2,k3,k4
		
		call f(t,x,k1)
		call f(t+c(2)*h, x+h*a(2,1)*k1, k2)
		call f(t+c(3)*h, x+h*(a(3,1)*k1+a(3,2)*k2), k3)
		call f(t+c(4)*h, x+h*(a(4,1)*k1+a(4,2)*k2+a(4,3)*k3), k4)
		r = h*(b(1)*k1+b(2)*k2+b(3)*k3+b(4)*k4);
	end subroutine rk
	
end program rkfts
