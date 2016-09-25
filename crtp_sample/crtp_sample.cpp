// crtp_sample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

template <class Derived>
class State_crtp {
public:
	void func0() {
		static_cast<Derived*>(this)->func0_impl();
	};
	void func0_impl() {
		printf("common hello world\n");
	}
private:

};

class State0 : public State_crtp<State0>{
public:
	void func0_impl() {
		printf("hello wolrd 0\n");
	};
private:

};

class State1 : public State_crtp<State1>{
public:
	void func0_impl() {
		printf("hello world 2\n");
	};
};

class State2 : public State_crtp<State2> {
public:

};

class State3 : public State_crtp<State3> {
public:

};





template <class crtp>
void wrap_func0(crtp& a) {
	a.func0();
}


class factory {
public:
	template<int A>
	auto get_state();

	template<0>
	auto get_state() {
		return Manage::state0;
	}

	template<1>
	auto get_state() {
		return Manage::state1;
	}

	template<2>
	auto get_state() {
		return Manage::state2;
	}

private:

};


class Manage {                      

public:
	template<typename prestate, typename poststate>
	void Transition(int nState) 
	{
		if(nState==0)	m_pState  = &state0;
		else if (nState == 1) m_pState = &state1;
	};

	void func0()
	{
		auto fn = vState[m_nState].func0;
		fn();
	}

private:
	friend class factory;
	static State_crtp<State0> state0;
	static State_crtp<State1> state1;
	static State_crtp<State2> state2;
};

static Manage manager;


int main()
{
	factory fac;
	constexpr int a = 2;
	a = 0;
	fac.get_state<a>.func0();

	/*
	State_crtp<State0> state0;
	State_crtp<State1> state1;
	State_crtp<State2> state2;
	wrap_func0(state0);
	wrap_func0(state1);
	wrap_func0(state2);
	*/
	/*
	constexpr int a=0;

	CState<a> aa;

	CBaseState* p = NULL;
	p = &aa;
	p->func0();
	*/
    return 0;
}

