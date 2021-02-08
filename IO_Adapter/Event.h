#pragma once

enum class KeyCode { W, A, S, D, UP, DOWN, LEFT, RIGHT, RIGHT_CTRL, LEFT_CTRL, RIGHT_SHIFT, LEFT_SHIFT, SPACE, RETURN, UNKNOWN };
enum class MouseButton { LEFT, RIGHT, MIDDLE };

class Event {

public:
	enum TYPE { 
		CLOSED, 
		KEY_DOWN, 
		KEY_UP, 
		MOUSE_BUTTON_UP, 
		MOUSE_BUTTON_DOWN, 
		UNKNOWN };

	TYPE type;

	union {
		KeyCode key;
		MouseButton button;
	};

};