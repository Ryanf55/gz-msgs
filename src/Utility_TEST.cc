/*
 * Copyright (C) 2016 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#include <gtest/gtest.h>
#include "ignition/msgs/MessageTypes.hh"
#include "ignition/msgs/Utility.hh"

using namespace ignition;

/////////////////////////////////////////////////
TEST(UtilityTest, CovertMathVector3ToMsgs)
{
  msgs::Vector3d msg = msgs::Convert(math::Vector3d(1, 2, 3));
  EXPECT_DOUBLE_EQ(1, msg.x());
  EXPECT_DOUBLE_EQ(2, msg.y());
  EXPECT_DOUBLE_EQ(3, msg.z());
}

/////////////////////////////////////////////////
TEST(UtilityTest, ConvertMsgsVector3dToMath)
{
  msgs::Vector3d msg = msgs::Convert(math::Vector3d(1, 2, 3));
  math::Vector3d v = msgs::Convert(msg);
  EXPECT_DOUBLE_EQ(1, v.X());
  EXPECT_DOUBLE_EQ(2, v.Y());
  EXPECT_DOUBLE_EQ(3, v.Z());
}

/////////////////////////////////////////////////
TEST(UtilityTest, ConvertMathQuaterionToMsgs)
{
  msgs::Quaternion msg =
    msgs::Convert(math::Quaterniond(M_PI * 0.25, M_PI * 0.5, M_PI));

  EXPECT_TRUE(math::equal(msg.x(), -0.65328148243818818));
  EXPECT_TRUE(math::equal(msg.y(), 0.27059805007309856));
  EXPECT_TRUE(math::equal(msg.z(), 0.65328148243818829));
  EXPECT_TRUE(math::equal(msg.w(), 0.27059805007309851));
}

/////////////////////////////////////////////////
TEST(UtilityTest, ConvertMsgsQuaterionToMath)
{
  msgs::Quaternion msg =
    msgs::Convert(math::Quaterniond(M_PI * 0.25, M_PI * 0.5, M_PI));
  math::Quaterniond v = msgs::Convert(msg);

  // TODO: to real unit test move math::equal to EXPECT_DOUBLE_EQ
  EXPECT_TRUE(math::equal(v.X(), -0.65328148243818818));
  EXPECT_TRUE(math::equal(v.Y(), 0.27059805007309856));
  EXPECT_TRUE(math::equal(v.Z(), 0.65328148243818829));
  EXPECT_TRUE(math::equal(v.W(), 0.27059805007309851));
}

/////////////////////////////////////////////////
TEST(UtilityTest, ConvertPoseMathToMsgs)
{
  msgs::Pose msg = msgs::Convert(math::Pose3d(
        math::Vector3d(1, 2, 3),
        math::Quaterniond(M_PI * 0.25, M_PI * 0.5, M_PI)));

  EXPECT_DOUBLE_EQ(1, msg.position().x());
  EXPECT_DOUBLE_EQ(2, msg.position().y());
  EXPECT_DOUBLE_EQ(3, msg.position().z());

  EXPECT_TRUE(math::equal(msg.orientation().x(), -0.65328148243818818));
  EXPECT_TRUE(math::equal(msg.orientation().y(), 0.27059805007309856));
  EXPECT_TRUE(math::equal(msg.orientation().z(), 0.65328148243818829));
  EXPECT_TRUE(math::equal(msg.orientation().w(), 0.27059805007309851));
}

/////////////////////////////////////////////////
TEST(UtilityTest, ConvertMsgPoseToMath)
{
  msgs::Pose msg = msgs::Convert(
      math::Pose3d(math::Vector3d(1, 2, 3),
        math::Quaterniond(M_PI * 0.25, M_PI * 0.5, M_PI)));
  math::Pose3d v = msgs::Convert(msg);

  EXPECT_DOUBLE_EQ(1, v.Pos().X());
  EXPECT_DOUBLE_EQ(2, v.Pos().Y());
  EXPECT_DOUBLE_EQ(3, v.Pos().Z());
  EXPECT_TRUE(math::equal(v.Rot().X(), -0.65328148243818818));
  EXPECT_TRUE(math::equal(v.Rot().Y(), 0.27059805007309856));
  EXPECT_TRUE(math::equal(v.Rot().Z(), 0.65328148243818829));
  EXPECT_TRUE(math::equal(v.Rot().W(), 0.27059805007309851));
}

/////////////////////////////////////////////////
TEST(UtilityTest, ConvertMathPlaneToMsgs)
{
  msgs::PlaneGeom msg = msgs::Convert(
      math::Planed(math::Vector3d(0, 0, 1),
        math::Vector2d(123, 456), 1.0));

  EXPECT_DOUBLE_EQ(0, msg.normal().x());
  EXPECT_DOUBLE_EQ(0, msg.normal().y());
  EXPECT_DOUBLE_EQ(1, msg.normal().z());

  EXPECT_DOUBLE_EQ(123, msg.size().x());
  EXPECT_DOUBLE_EQ(456, msg.size().y());
}

/////////////////////////////////////////////////
TEST(UtilityTest, ConvertMsgsPlaneToMath)
{
  msgs::PlaneGeom msg = msgs::Convert(
      math::Planed(math::Vector3d(0, 0, 1),
        math::Vector2d(123, 456), 1.0));
  math::Planed v = msgs::Convert(msg);

  EXPECT_DOUBLE_EQ(0, v.Normal().X());
  EXPECT_DOUBLE_EQ(0, v.Normal().Y());
  EXPECT_DOUBLE_EQ(1, v.Normal().Z());

  EXPECT_DOUBLE_EQ(123, v.Size().X());
  EXPECT_DOUBLE_EQ(456, v.Size().Y());

  EXPECT_TRUE(math::equal(1.0, v.Offset()));
}

/////////////////////////////////////////////////
// TEST(UtilityTest, ConvertDoubleToAny)
// {
//   ignition::msgs::Any msg = msgs::ConvertAny(1.0);
//   EXPECT_EQ(msg.type(), ignition::msgs::Any::DOUBLE);
//   ASSERT_TRUE(msg.has_double_value());
//   EXPECT_DOUBLE_EQ(1, msg.double_value());
// }
//
// /////////////////////////////////////////////////
// TEST(UtilityTest, ConvertIntToAny)
// {
//   ignition::msgs::Any msg = msgs::ConvertAny(2);
//   EXPECT_EQ(msg.type(), ignition::msgs::Any::INT32);
//   ASSERT_TRUE(msg.has_int_value());
//   EXPECT_DOUBLE_EQ(2, msg.int_value());
// }
//
// /////////////////////////////////////////////////
// TEST(UtilityTest, ConvertStringToAny)
// {
//   ignition::msgs::Any msg = msgs::ConvertAny("test_string");
//   EXPECT_EQ(msg.type(), ignition::msgs::Any::STRING);
//   ASSERT_TRUE(msg.has_string_value());
//   EXPECT_EQ("test_string", msg.string_value());
// }
//
// /////////////////////////////////////////////////
// TEST(UtilityTest, ConvertBoolToAny)
// {
//   ignition::msgs::Any msg = msgs::ConvertAny(true);
//
//   EXPECT_EQ(msg.type(), ignition::msgs::Any::BOOLEAN);
//   ASSERT_TRUE(msg.has_bool_value());
//   EXPECT_TRUE(msg.bool_value());
// }
//
// /////////////////////////////////////////////////
// TEST(UtilityTest, ConvertVector3dToAny)
// {
//   ignition::msgs::Any msg = msgs::ConvertAny(ignition::math::Vector3d(1, 2, 3));
//   EXPECT_EQ(msg.type(), ignition::msgs::Any::VECTOR3D);
//   ASSERT_TRUE(msg.has_vector3d_value());
//
//   EXPECT_DOUBLE_EQ(1, msg.vector3d_value().x());
//   EXPECT_DOUBLE_EQ(2, msg.vector3d_value().y());
//   EXPECT_DOUBLE_EQ(3, msg.vector3d_value().z());
// }
//
// /////////////////////////////////////////////////
// TEST(UtilityTest, ConvertPose3dToAny)
// {
//   ignition::msgs::Any msg = msgs::ConvertAny(ignition::math::Pose3d(
//       ignition::math::Vector3d(1, 2, 3),
//       ignition::math::Quaterniond(4, 5, 6, 7)));
//
//   EXPECT_EQ(msg.type(), ignition::msgs::Any::POSE3D);
//   ASSERT_TRUE(msg.has_pose3d_value());
//
//   EXPECT_DOUBLE_EQ(1, msg.pose3d_value().position().x());
//   EXPECT_DOUBLE_EQ(2, msg.pose3d_value().position().y());
//   EXPECT_DOUBLE_EQ(3, msg.pose3d_value().position().z());
//
//   EXPECT_TRUE(math::equal(msg.pose3d_value().orientation().w(), 4.0));
//   EXPECT_TRUE(math::equal(msg.pose3d_value().orientation().x(), 5.0));
//   EXPECT_TRUE(math::equal(msg.pose3d_value().orientation().y(), 6.0));
//   EXPECT_TRUE(math::equal(msg.pose3d_value().orientation().z(), 7.0));
// }
//
// /////////////////////////////////////////////////
// TEST(UtilityTest, ConvertQuaternionToAny)
// {
//   ignition::msgs::Any msg = msgs::ConvertAny(
//       ignition::math::Quaterniond(1, 2, 3, 4));
//
//   EXPECT_EQ(msg.type(), ignition::msgs::Any::QUATERNIOND);
//   ASSERT_TRUE(msg.has_quaternion_value());
//
//   EXPECT_TRUE(math::equal(msg.quaternion_value().w(), 1.0));
//   EXPECT_TRUE(math::equal(msg.quaternion_value().x(), 2.0));
//   EXPECT_TRUE(math::equal(msg.quaternion_value().y(), 3.0));
//   EXPECT_TRUE(math::equal(msg.quaternion_value().z(), 4.0));
// }

/////////////////////////////////////////////////
TEST(UtilityTest, SetVector3)
{
  msgs::Vector3d msg;
  msgs::Set(&msg, math::Vector3d(1, 2, 3));
  EXPECT_DOUBLE_EQ(1, msg.x());
  EXPECT_DOUBLE_EQ(2, msg.y());
  EXPECT_DOUBLE_EQ(3, msg.z());
}

/////////////////////////////////////////////////
TEST(UtilityTest, SetVector2d)
{
  msgs::Vector2d msg;
  msgs::Set(&msg, math::Vector2d(1, 2));
  EXPECT_DOUBLE_EQ(1, msg.x());
  EXPECT_DOUBLE_EQ(2, msg.y());
}

/////////////////////////////////////////////////
TEST(UtilityTest, SetQuaternion)
{
  msgs::Quaternion msg;
  msgs::Set(&msg, math::Quaterniond(M_PI * 0.25, M_PI * 0.5, M_PI));
  EXPECT_TRUE(math::equal(msg.x(), -0.65328148243818818));
  EXPECT_TRUE(math::equal(msg.y(), 0.27059805007309856));
  EXPECT_TRUE(math::equal(msg.z(), 0.65328148243818829));
  EXPECT_TRUE(math::equal(msg.w(), 0.27059805007309851));
}

/////////////////////////////////////////////////
TEST(UtilityTest, SetPose)
{
  msgs::Pose msg;
  msgs::Set(&msg, math::Pose3d(math::Vector3d(1, 2, 3),
        math::Quaterniond(M_PI * 0.25, M_PI * 0.5, M_PI)));

  EXPECT_DOUBLE_EQ(1, msg.position().x());
  EXPECT_DOUBLE_EQ(2, msg.position().y());
  EXPECT_DOUBLE_EQ(3, msg.position().z());

  EXPECT_TRUE(math::equal(msg.orientation().x(), -0.65328148243818818));
  EXPECT_TRUE(math::equal(msg.orientation().y(), 0.27059805007309856));
  EXPECT_TRUE(math::equal(msg.orientation().z(), 0.65328148243818829));
  EXPECT_TRUE(math::equal(msg.orientation().w(), 0.27059805007309851));
}

/////////////////////////////////////////////////
TEST(UtilityTest, SetPlane)
{
  msgs::PlaneGeom msg;
  msgs::Set(&msg, math::Planed(
        math::Vector3d(0, 0, 1),
        math::Vector2d(123, 456), 1.0));

  EXPECT_DOUBLE_EQ(0, msg.normal().x());
  EXPECT_DOUBLE_EQ(0, msg.normal().y());
  EXPECT_DOUBLE_EQ(1, msg.normal().z());

  EXPECT_DOUBLE_EQ(123, msg.size().x());
  EXPECT_DOUBLE_EQ(456, msg.size().y());

  EXPECT_TRUE(math::equal(1.0, msg.d()));
}

/////////////////////////////////////////////////
TEST(UtilityTest, Initialization)
{
  {
    msgs::Vector3d msg;
    EXPECT_DOUBLE_EQ(0, msg.x());
    EXPECT_DOUBLE_EQ(0, msg.y());
    EXPECT_DOUBLE_EQ(0, msg.z());
  }

  {
    msgs::Wrench msg;
    EXPECT_DOUBLE_EQ(0, msg.force().x());
    EXPECT_DOUBLE_EQ(0, msg.force().y());
    EXPECT_DOUBLE_EQ(0, msg.force().z());
    EXPECT_DOUBLE_EQ(0, msg.torque().x());
    EXPECT_DOUBLE_EQ(0, msg.torque().y());
    EXPECT_DOUBLE_EQ(0, msg.torque().z());
  }
}
