#ifndef Vec_h
#define Vec_h

class Vec {
	float x;
	float y;
	float z;




public:

	Vec() {

		x = 0;
		y = 0;
	}

	Vec(double x, double y) {

		this->x = x;
		this->y = y;
	}
	
	Vec(double x, double y, double z) {

		this->x = x;
		this->y = y;
		this->z = z;



	}

	float getX() const {

		return x;

	}

	float getY() const {


		return y;
	}

	float getZ() const {

		return z;
	}
	

	void setX(float x) {
		this->x = x;

	}


	void setY(float y) {
		this->y = y;

	}

	void setZ(float z) {
		this->z = z;


	}

	void add(Vec a) {
		x += a.x;
		y += a.y;

	}
















};
#endif