#pragma once

#include "controller.h"

/** @brief The KeyboardManager class handles keyboard input. */
class KeyboardController : public Controller
{
public:
    explicit KeyboardController(QObject* _parent);

protected:
    bool eventFilter(QObject* object, QEvent* event) Q_DECL_OVERRIDE;
};
