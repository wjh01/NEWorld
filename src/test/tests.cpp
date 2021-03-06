/*
* NEWorld: A free game with similar rules to Minecraft.
* Copyright (C) 2016 NEWorld Team
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <gtest/gtest.h>

//***********Vec3***********//

#include <vec3.h>
TEST(Vec3, Basic)
{
    Vec3<int> v(1, 2, 3);
    EXPECT_EQ(v.x + v.y*v.z, 7);
}
TEST(Vec3, Length)
{
    Vec3<int> v(3, 6, 6);
    EXPECT_EQ(v.length(), 9);
}
TEST(Vec3, for_each)
{
    Vec3<int> v(3, 6, 6);
    v.for_each([](int& x,int y) { x+=y; }, 1);
    EXPECT_EQ(v.lengthSqr(), 114);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
