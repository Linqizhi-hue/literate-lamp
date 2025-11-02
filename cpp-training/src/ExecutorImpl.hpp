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
    void Move(void) noexcept;
    void TurnLeft(void) noexcept;
    void TurnRight(void) noexcept;
    void Fast(void) noexcept;
    bool IsFast(void) const noexcept;
    Pose pose;
    bool fast{false};
private:
    PoseHandler poseHandler;
private:
    class MoveCommand final
    {
    public:
        const std::function<void(PoseHandler& poseHandler)> operate = [](PoseHandler& poseHandler) noexcept {
            if (poseHandler.IsFast()) {
                poseHandler.Move();
            }
            poseHandler.Move();
        };
    };
    class TurnLeftCommand final
    {
    public:
        const std::function<void(PoseHandler& poseHandler)> operate = [](PoseHandler& poseHandler) noexcept {
            if (poseHandler.IsFast()) {
                poseHandler.Move();
            }
            poseHandler.TurnLeft();
        };
    };
    class TurnRightCommand final
    {
    public:
        const std::function<void(PoseHandler& poseHandler)> operate = [](PoseHandler& poseHandler) noexcept {
            if (poseHandler.IsFast()) {
                poseHandler.Move();
            }
            poseHandler.TurnRight();
        };
    };
    class FastCommand final
    {
    public:
        const std::function<void(PoseHandler& poseHandler)> operate = [](PoseHandler& poseHandler) noexcept {
            poseHandler.Fast();
        };
    };
};
};
