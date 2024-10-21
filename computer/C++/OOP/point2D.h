//  cài đặt phương thức lồng bên trong lớp
class point2D {
	double x, y;
public:
	void set(double x0, double y0) {
		x = x0;
		y = y0;
	}

	void move(double dx, double dy) {
		x += dx;
		y += dy;
	}

	void scale(double sx, double sy) {
		x *= sx;
		y *= sy;
	}
}; // end of point2D class