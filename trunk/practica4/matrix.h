class Matrix {

public:
	Matrix(unsigned rows, unsigned cols);
	double& operator() (unsigned row, unsigned col);        //subscript operators often come in pairs
	double  operator() (unsigned row, unsigned col) const;  //subscript operators often come in pairs
	~Matrix();                              // Destructor
	
	Matrix(Matrix const& m);               // Copy constructor
	Matrix& operator= (Matrix const& m);   // Assignment operator
private:
	unsigned rows_, cols_;
	double* data_;

};