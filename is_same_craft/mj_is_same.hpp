#pragma once

namespace cdsim
{
	template<typename T1, typename T2>
	class is_same
	{
	public:
		constexpr static bool value = false;
	};


	template<typename T>
	class is_same <T,T>
	{                                                    
	public:                                              
		constexpr static bool value = true;
	};                                             
};