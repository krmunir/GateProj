#pragma once
class Led
{
public:
	enum State {
		OFF,
		ON,
		NUM_STATES
	};

	struct Param {
		u_char brightness; //0-255
		std::string colour = "#RRGGBB";
	};

	Led();
	~Led();
	void setup(Param configSetup[]);
	void changeStateTo(State newState);
private:
	State m_currState;
	Param m_config[State::NUM_STATES];
};

class Button
{
public:
	enum State {
		IDLE,
		OPERATING,
		NUM_STATES
	};

	struct Param {
		std::string onLblText; 
		std::string offLblText; 
		std::string colour = "#RRGGBB";
	};

	Button();
	~Button();
	void setup(Param configSetup[]);
	void changeStateTo(State newState);
private:
	State m_currState;
	Param m_config[State::NUM_STATES];
};

class StyledButton
{
public:
	enum State {
		IDLE,
		FULLY_OPENING,
		HALF_OPENING,
		FULLY_CLOSING,
		NUM_STATES
	};

	struct Param {
		std::string offLblText;
		std::string offLblTextCol = "#RRGGBB";
		std::string offBgCol = "#RRGGBB";
		std::string onLblText;
		std::string onLblTextCol = "#RRGGBB";
		std::string onBgCol = "#RRGGBB";
	};

	StyledButton();
	~StyledButton();
	void setup(Param configSetup[]);
	void changeStateTo(State newState);
private:
	State m_currState;
	Param m_config[State::NUM_STATES];
};

