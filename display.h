#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>

class Display
{
	private:
	std::string m_borderSpace;
	std::string m_playerBanner;
	std::string m_colLabel;
	std::string m_rowiLabel;
	std::string m_gridLine;
	std::string m_borderLine;
	std::string m_friendlyBanner;

	public:
	Display();
};
#endif
