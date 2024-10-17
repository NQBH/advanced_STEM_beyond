program rkats
	use vdp ! module for systems of ODEs
	implicit none
	real (kind = 8) :: h=1d-5,htol=1d-9,at=1d-4,rt=1d-3 ! error tolerance
	real (kind = 8) :: fac=0.9d0,facmin=0.5d0,facmax=2d0
	real (kind = 8) :: s,er,start,finish
	integer :: i,j=1,p=2,v1,v2,inputerror
	real (kind = 8), dimension(dms) :: r2,r3,x2,x3,e
	real (kind = 8), dimension(4,4) :: a2,a3
	real (kind = 8), dimension(4) :: b2,b3,c2,c3
	
	call cpu_time(start)
	a2=reshape((/0.0,0.0,0.0,0.0,&
		1.0,0.0,0.0,0.0,&
		0.0,0.0,0.0,0.0,&
		0.0,0.0,0.0,0.0/)&
		,shape(a2),order=(/2,1/))
	b2=(/0.5,0.5,0.0,0.0/)
	c2=(/0.0,1.0,0.0,0.0/)

	a3=reshape((/0.0,0.0,0.0,0.0,&
		1.0,0.0,0.0,0.0,&
		0.25,0.25,0.0,0.0,&
		0.0,0.0,0.0,0.0/)&
		,shape(a3),order=(/2,1/))
	b3=(/1/6d0,1/6d0,2/3d0,0d0/)
	c3=(/0.0,1.0,0.5,0.0/)

	open(unit=1,file="data.txt",form="formatted",status="replace",action="write")
	do while (t<=te)
		call rk(a2,b2,c2,a3,b3,c3,h,t,x,x2,x3)
		r2=x+x2
		r3=x+x3
		s=0d0
		do i=1,dms
			s=s+((r2(i)-r3(i))/(at+max(abs(r2(i)),abs(r3(i)))*rt))**2
		end do
		er=sqrt(s/d)
		if (er>1d0) then
			facmax=1d0
			h=h*min(facmax,max(facmin,fac/(er**(1/4d0))))
			if (h<=htol) then
				print *, 'stop'
				stop
			else 
				cycle
			end if
		end if
		write(1,*) t,h,(x(i), i=1,dms)
		x=r3
		t=t+h
		facmax=2d0
		h=h*min(facmax,max(facmin,fac/(er**(1/4d0))))
	end do
	!write(1,*) t,h,(x(i), i=1,dms)
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
	subroutine rk(a1,b1,c1,a2,b2,c2,h,t,x,x1,x2)
		implicit none
		real (kind = 8), intent(in) :: t,h
		real (kind = 8), dimension(dms), intent(in) :: x
		real (kind = 8), dimension(4,4), intent(in) :: a1, a2
		real (kind = 8), dimension(4), intent(in) :: b1, c1, b2, c2
		real (kind = 8), dimension(dms), intent(out) :: x1, x2
		real (kind = 8), dimension(dms) :: k1,k2,k3,k4
		
		call f(t,x,k1)
		call f(t+c1(2)*h, x+h*a1(2,1)*k1, k2)
		call f(t+c1(3)*h, x+h*(a1(3,1)*k1+a1(3,2)*k2), k3)
		call f(t+c1(4)*h, x+h*(a1(4,1)*k1+a1(4,2)*k2+a1(4,3)*k3), k4)
		x1 = h*(b1(1)*k1+b1(2)*k2+b2(3)*k3+b1(4)*k4);

		call f(t+c2(2)*h, x+h*a2(2,1)*k1, k2)
		call f(t+c2(3)*h, x+h*(a2(3,1)*k1+a2(3,2)*k2), k3)
		call f(t+c2(4)*h, x+h*(a2(4,1)*k1+a2(4,2)*k2+a2(4,3)*k3), k4)
		x2 = h*(b2(1)*k1+b2(2)*k2+b2(3)*k3+b2(4)*k4);
	end subroutine rk
	
end program rkats
