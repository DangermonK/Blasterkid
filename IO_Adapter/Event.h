#pragma once

enum class KeyCode { A, B, C, D, UNKNOWN };
enum class MouseButton { LEFT, RIGHT, MIDDLE };

class Event {

public:
	enum TYPE { CLOSED, KEY_DOWN, KEY_UP, MOUSE_BUTTON_UP, MOUSE_BUTTON_DOWN, UNKNOWN };

	TYPE type;

	union {
		KeyCode key;
		MouseButton button;
	};
};