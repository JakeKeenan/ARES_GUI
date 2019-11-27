#pragma once
#include <iostream>
class Data
{
public:
	struct Vector3D
	{
		double x = 0;
		double y = 0;
		double z = 0;
	};
	struct ApproachPatternInputs
	{
		std::string approachPattern = "";
		double closureRateGain = 0;
		Vector3D locationVector;
	};
	struct InputProperties
	{
		double hoseAeroGain = 0;
		double drogueAeroGain = 0;
		double hoseStiffnessGain = 0;
		double hoseDampingGain = 0;
	};
	static ApproachPatternInputs APPROACH_PATTERN_INPUTS;
	static InputProperties INPUT_PROPERTIES;
	static std::string INPUT_RECEIVER_FILE;
	static std::string INPUT_TANKER_FILE;

};

