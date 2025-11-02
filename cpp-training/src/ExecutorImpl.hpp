#pragma once
#include <functional>
#include "Executor.hpp"
#include "PoseHandler.hpp"
namespace adas
{
class ExecutorImpl final : public Executor
{
public:
    explicit ExecutorImpl(const Pose& pose) noexcept;
    ~ExecutorImpl() noexcept = default;
    ExecutorImpl(const ExecutorImpl&) = delete;
    ExecutorImpl& operator=(const ExecutorImpl&) = delete;
public:
    void Execute(const std::string& command) noexcept override;
    Pose Query(void) const noexcept override;
public:
    void Forward(void) noexcept;
    void TurnLeft(void) noexcept;
    void TurnRight(void) noexcept;
    void Backward(void) noexcept;
    void Fast(void) noexcept;
    bool IsFast(void) const noexcept;
    void Reverse(void) noexcept;
    bool IsReverse(void) const noexcept;
    Pose pose;
    bool fast{false};
    bool reverse{false};
private:
    PoseHandler poseHandler;
private:
    class MoveCommand final
    {
    public:
        void operator()(PoseHandler& poseHandler) const noexcept
        {
            if (poseHandler.IsFast()) {
                if (poseHandler.IsReverse()) {
                    poseHandler.Backward();
                } else {
                    poseHandler.Forward();
                }
            }
            if (poseHandler.IsReverse()) {
                poseHandler.Backward();
            } else {
                poseHandler.Forward();
            }
        }
    };
    class TurnLeftCommand final
    {
    public:
        void operator()(PoseHandler& poseHandler) const noexcept
        {
            if (poseHandler.IsFast()) {
                if (poseHandler.IsReverse()) {
                    poseHandler.Backward();
                } else {
                    poseHandler.Forward();
                }
            }
            if (poseHandler.IsReverse()) {
                poseHandler.TurnRight();
            } else {
                poseHandler.TurnLeft();
            }
        }
    };
    class TurnRightCommand final
    {
    public:
        void operator()(PoseHandler& poseHandler) const noexcept
        {
            if (poseHandler.IsFast()) {
                if (poseHandler.IsReverse()) {
                    poseHandler.Backward();
                } else {
                    poseHandler.Forward();
                }
            }
            if (poseHandler.IsReverse()) {
                poseHandler.TurnLeft();
            } else {
                poseHandler.TurnRight();
            }
        }
    };
    class FastCommand final
    {
    public:
        void operator()(PoseHandler& poseHandler) const noexcept
        {
            poseHandler.Fast();
        }
    };
    class ReverseCommand final
    {
    public:
        void operator()(PoseHandler& poseHandler) const noexcept
        {
            poseHandler.Reverse();
        }
    };
};
};
