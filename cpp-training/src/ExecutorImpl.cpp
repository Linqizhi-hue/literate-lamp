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
        if (pose.heading=='E') {
            pose.x+=1;
        }
        else if (pose.heading=='W') {
            pose.x-=1;
        }
        else if (pose.heading=='N') {
            pose.y+=1;
        }
        else if (pose.heading=='S') {
            pose.y-=1;
        }
    }
}
Pose ExecutorImpl::Query() const noexcept
{
    return pose;
}
} 