#include "appWidgets.h"
#include <BlynkSimpleEsp8266.h>


Led::Led() {

}

Led::~Led() {

}

void Led::setup(Param configSetup[]) {
	m_config[OFF].brightness = configSetup[OFF].brightness;
	m_config[OFF].colour = configSetup[OFF].colour;
	m_config[ON].brightness = configSetup[ON].brightness;
	m_config[ON].colour = configSetup[ON].colour;
}

void Led::changeStateTo(State newState) {

}

Button::Button() {

}

Button::~Button() {

}

void Button::setup(Param configSetup[]) {
	m_config[IDLE].onLblText = configSetup[IDLE].onLblText;
	m_config[IDLE].offLblText = configSetup[IDLE].offLblText;
	m_config[IDLE].colour = configSetup[IDLE].colour;
	m_config[OPERATING].onLblText = configSetup[OPERATING].onLblText;
	m_config[OPERATING].offLblText = configSetup[OPERATING].offLblText;
	m_config[OPERATING].colour = configSetup[OPERATING].colour;
}

void Button::changeStateTo(State newState) {

}


StyledButton::StyledButton() {

}

StyledButton::~StyledButton() {

}

void StyledButton::setup(Param configSetup[]) {
	m_config[IDLE].offLblText = configSetup[IDLE].offLblText;
	m_config[IDLE].offLblTextCol = configSetup[IDLE].offLblTextCol;
	m_config[IDLE].offBgCol = configSetup[IDLE].offBgCol;
	m_config[IDLE].onLblText = configSetup[IDLE].onLblText;
	m_config[IDLE].onLblTextCol = configSetup[IDLE].onLblTextCol;
	m_config[IDLE].onBgCol = configSetup[IDLE].onBgCol;
	m_config[FULLY_OPENING].offLblText = configSetup[FULLY_OPENING].offLblText;
	m_config[FULLY_OPENING].offLblTextCol = configSetup[FULLY_OPENING].offLblTextCol;
	m_config[FULLY_OPENING].offBgCol = configSetup[FULLY_OPENING].offBgCol;
	m_config[FULLY_OPENING].onLblText = configSetup[FULLY_OPENING].onLblText;
	m_config[FULLY_OPENING].onLblTextCol = configSetup[FULLY_OPENING].onLblTextCol;
	m_config[FULLY_OPENING].onBgCol = configSetup[FULLY_OPENING].onBgCol;
	m_config[HALF_OPENING].offLblText = configSetup[HALF_OPENING].offLblText;
	m_config[HALF_OPENING].offLblTextCol = configSetup[HALF_OPENING].offLblTextCol;
	m_config[HALF_OPENING].offBgCol = configSetup[HALF_OPENING].offBgCol;
	m_config[HALF_OPENING].onLblText = configSetup[HALF_OPENING].onLblText;
	m_config[HALF_OPENING].onLblTextCol = configSetup[HALF_OPENING].onLblTextCol;
	m_config[HALF_OPENING].onBgCol = configSetup[HALF_OPENING].onBgCol;
	m_config[FULLY_CLOSING].offLblText = configSetup[FULLY_CLOSING].offLblText;
	m_config[FULLY_CLOSING].offLblTextCol = configSetup[FULLY_CLOSING].offLblTextCol;
	m_config[FULLY_CLOSING].offBgCol = configSetup[FULLY_CLOSING].offBgCol;
	m_config[FULLY_CLOSING].onLblText = configSetup[FULLY_CLOSING].onLblText;
	m_config[FULLY_CLOSING].onLblTextCol = configSetup[FULLY_CLOSING].onLblTextCol;
	m_config[FULLY_CLOSING].onBgCol = configSetup[FULLY_CLOSING].onBgCol;
}

void StyledButton::changeStateTo(State newState) {

}

