#include <gtest/gtest.h>

#include "Executor.hpp"
#include "PoseEq.hpp"
namespace adas
{
TEST(ExecutorReverseTest, should_return_x_minus_1_given_status_is_back_command_is_M_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    executor->Execute("BM");
    const Pose target{-1, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorReverseTest, should_return_y_minus_1_given_status_is_back_command_is_M_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    executor->Execute("BM");
    const Pose target{0, -1, 'N'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorReverseTest, should_return_x_plus_1_given_status_is_back_command_is_M_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
    executor->Execute("BM");
    const Pose target{1, 0, 'W'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorReverseTest, should_return_y_plus_1_given_status_is_back_command_is_M_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
    executor->Execute("BM");
    const Pose target{0, 1, 'S'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorReverseTest, should_return_facing_S_given_status_is_back_command_is_L_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    executor->Execute("BL");
    const Pose target{0, 0, 'S'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorReverseTest, should_return_facing_W_given_status_is_back_command_is_L_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
    executor->Execute("BL");
    const Pose target{0, 0, 'W'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorReverseTest, should_return_facing_N_given_status_is_back_command_is_L_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
    executor->Execute("BL");
    const Pose target{0, 0, 'N'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorReverseTest, should_return_facing_E_given_status_is_back_command_is_L_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    executor->Execute("BL");
    const Pose target{0, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorReverseTest, should_return_facing_N_given_status_is_back_command_is_R_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    executor->Execute("BR");
    const Pose target{0, 0, 'N'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorReverseTest, should_return_facing_W_given_status_is_back_command_is_R_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    executor->Execute("BR");
    const Pose target{0, 0, 'W'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorReverseTest, should_return_facing_S_given_status_is_back_command_is_R_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
    executor->Execute("BR");
    const Pose target{0, 0,'S'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorReverseTest, sould_return_facing_E_given_status_is_back_command_is_R_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
    executor->Execute("BR");
    const Pose target{0, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorReverseTest, should_return_x_minus_2_given_status_is_back_and_fast_command_is_M_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    executor->Execute("BFM");
    const Pose target{-2, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorReverseTest, should_return_y_minus_2_given_status_is_back_and_fast_command_is_M_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    executor->Execute("BFM");
    const Pose target{0, -2, 'N'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorReverseTest, should_return_x_plus_2_given_status_is_back_and_fast_command_is_M_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
    executor->Execute("BFM");
    const Pose target{2, 0, 'W'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorReverseTest, should_return_y_plus_2_given_status_is_back_and_fast_command_is_M_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
    executor->Execute("BFM");
    const Pose target{0, 2, 'S'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorReverseTest, should_return_x_minus_1_and_facing_S_given_status_is_back_and_fast_command_is_L_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    executor->Execute("BFL");
    const Pose target{-1, 0, 'S'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorReverseTest, should_return_y_plus_1_and_facing_W_given_status_is_back_and_fast_command_is_L_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
    executor->Execute("BFL");
    const Pose target{0, 1, 'W'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorReverseTest,should_return_x_plus_1_and_facing_N_given_status_is_back_and_fast_command_is_L_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
    executor->Execute("BFL");
    const Pose target{1, 0, 'N'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorReverseTest,should_return_y_minus_1_and_facing_E_given_status_is_back_and_fast_command_is_L_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    executor->Execute("BFL");
    const Pose target{0, -1, 'E'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorReverseTest,should_return_x_minus_1_and_facing_N_given_status_is_back_and_fast_command_is_R_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    executor->Execute("BFR");
    const Pose target{-1, 0, 'N'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorReverseTest,should_return_y_minus_1_and_facing_W_given_status_is_back_and_fast_command_is_R_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    executor->Execute("BFR");
    const Pose target{0, -1, 'W'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorReverseTest,should_return_x_plus_1_and_facing_S_given_status_is_back_and_fast_command_is_R_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
    executor->Execute("BFR");
    const Pose target{1, 0, 'S'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorReverseTest,should_return_y_plus_1_and_facing_E_given_status_is_back_and_fast_command_is_R_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
    executor->Execute("BFR");
    const Pose target{0, 1, 'E'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorReverseTest,should_return_y_plus_1_command_is_BBM_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor());
    executor->Execute("BBM");
    const Pose target{0, 1, 'N'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorReverseTest, should_return_facing_W_command_is_BBL_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor());
    executor->Execute("BBL");
    const Pose target{0, 0, 'W'};
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorReverseTest, should_return_facing_E_command_is_BBR_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor());
    executor->Execute("BBR");
    const Pose target{0, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}
}