#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "db_interface.h"
#include "my_comp.h"

using ::testing::_;
using ::testing::Return;
using ::testing::AtLeast;


class mock_db:public dbConnect{
	public:
	MOCK_METHOD2(login, int(const std::string&, const std::string&));
	MOCK_METHOD1(logout, int(const std::string&));
};

TEST(myComp, init_nulldb){
	myComp mc(nullptr, "user1", "P@$$");
	EXPECT_EQ(mc.init(),0);
}

TEST(myComp, init_success){
	mock_db dbo;
	myComp mc(&dbo, "user1", "P@$$");

	EXPECT_CALL(dbo, login("user1", "P@$$")).Times(1).WillOnce(Return(1));
	EXPECT_EQ(mc.init(),1);
}

TEST(myComp, init_fail){
	mock_db dbo;
	myComp mc(&dbo, "user1", "P@$$");

	EXPECT_CALL(dbo, login("user1", "P@$$")).Times(1).WillOnce(Return(0));
	EXPECT_EQ(mc.init(),0);
}

TEST(myComp, stop_nulldb){
	myComp mc(nullptr, "user1", "P@$$");
	EXPECT_EQ(mc.stop(),0);
}

TEST(myComp, stop_success){
	mock_db dbo;
	myComp mc(&dbo, "user1", "P@$$");

	EXPECT_CALL(dbo, logout("user1")).Times(1).WillOnce(Return(1));
	EXPECT_EQ(mc.stop(),1);
}

TEST(myComp, stop_fail){
	mock_db dbo;
	myComp mc(&dbo, "user1", "P@$$");
	EXPECT_CALL(dbo, logout("user1")).Times(1).WillOnce(Return(0));
	EXPECT_EQ(mc.stop(),0);
}


int main(int argc, char **argv){
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();	
}