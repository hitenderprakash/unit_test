#include <iostream>
#include <limits>
#include <dlfcn.h>
#include <gtest/gtest.h>

typedef double (*FPTR)(double,double);

class math_test: public ::testing::Test{
	protected:
	
	void *dlhndl;
	FPTR fpnAdd;
	FPTR fpnSubtract;
	FPTR fpnMultiply;
	FPTR fpnDivide;

	void SetUp(){
		dlhndl = dlopen("libmath.so",RTLD_NOW);	
		fpnAdd = (FPTR)dlsym(dlhndl,"add");
		fpnSubtract = (FPTR)dlsym(dlhndl,"subtract");
		fpnMultiply = (FPTR)dlsym(dlhndl,"multiply");
		fpnDivide = (FPTR)dlsym(dlhndl,"divide");
	}
	void TearDown(){
		dlclose(dlhndl);
	}
};

TEST_F(math_test, add){
	ASSERT_EQ(fpnAdd(1,2),3);
}

TEST_F(math_test, subtract){
	ASSERT_EQ(fpnSubtract(4,2),2);
}

TEST_F(math_test, multiply){
	ASSERT_EQ(fpnMultiply(5,6),30);
}

TEST_F(math_test, divide){
	ASSERT_EQ(fpnDivide(10,2),5);
}

TEST_F(math_test, divide2){
	ASSERT_EQ(fpnDivide(10,0),std::numeric_limits<double>::min());
}

int main(int argc, char **argv){
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();	
}