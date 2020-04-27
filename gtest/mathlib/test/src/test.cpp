#include <iostream>
#include <limits>
#include <dlfcn.h>
#include <gtest/gtest.h>

typedef double (*FPTR)(double,double);

TEST(math_test, add){
	void *dlhndl = dlopen("../libmath.so",RTLD_NOW);
	FPTR fpnAdd = (FPTR)dlsym(dlhndl,"add");
	ASSERT_EQ(fpnAdd(1,2),3);
	dlclose(dlhndl);
}

TEST(math_test, subtract){
	void *dlhndl = dlopen("../libmath.so",RTLD_NOW);
	FPTR fpnSubtract = (FPTR)dlsym(dlhndl,"subtract");
	ASSERT_EQ(fpnSubtract(4,2),2);
	dlclose(dlhndl);
}
TEST(math_test, multiply){
	void *dlhndl = dlopen("../libmath.so",RTLD_NOW);
	FPTR fpnMultiply = (FPTR)dlsym(dlhndl,"multiply");
	ASSERT_EQ(fpnMultiply(5,6),30);
	dlclose(dlhndl);
}
TEST(math_test, divide){
	void *dlhndl = dlopen("../libmath.so",RTLD_NOW);
	FPTR fpnDivide = (FPTR)dlsym(dlhndl,"divide");
	ASSERT_EQ(fpnDivide(10,2),5);
	dlclose(dlhndl);
}
TEST(math_test, divide2){
	void *dlhndl = dlopen("../libmath.so",RTLD_NOW);
	FPTR fpnDivide = (FPTR)dlsym(dlhndl,"divide");
	ASSERT_EQ(fpnDivide(10,0),std::numeric_limits<double>::min());
	dlclose(dlhndl);
}
int main(int argc, char **argv){
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();	
}