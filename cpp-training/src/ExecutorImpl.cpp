#include "ExecutorImpl.hpp"
namespace adas
{
Executor* Executor::NewExecutor(const Pose& pose) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose);
}
ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept : pose(pose)
{
}
void ExecutorImpl::Execute(const std::string& commands) noexcept
{
    if (commands =="M") {
        Move();
    }
    else if (commands == "L") {
        if (pose.heading == 'E') {
            pose.heading = 'N';
        } 
        else if (pose.heading == 'N') {
            pose.heading = 'W';
        } 
        else if (pose.heading == 'W') {
            pose.heading = 'S';
        } 
        else if (pose.heading == 'S') {
            pose.heading = 'E';
        }
    }
    else if (commands == "R") {
        if (pose.heading == 'E') {
            pose.heading = 'S';
        } 
        else if (pose.heading == 'S') {
            pose.heading = 'W';
        } 
        else if (pose.heading == 'W') {
            pose.heading = 'N';
        } 
        else if (pose.heading == 'N') {
            pose.heading = 'E';
        }
    }
}
Pose ExecutorImpl::Query() const noexcept
{
    return pose;
}
void ExecutorImpl::Move() noexcept
{
    if (pose.heading == 'E') {
        ++pose.x;
    } 
    else if (pose.heading == 'W') {
        --pose.x;
    } 
    else if (pose.heading == 'N') {
        ++pose.y;
    } 
    else if (pose.heading == 'S') {
        --pose.y;
    }
}
} 