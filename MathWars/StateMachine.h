#pragma once
#include "State.h"

#include <stack>
#include <memory>

namespace MathWars {
	typedef std::unique_ptr<State> StateRef;

	class StateMachine {
	public:
		StateMachine() {}
		~StateMachine() {}

		void AddState(StateRef newState, bool isReplacing = true);
		void RemoveState();

		void ProcessStateChanges();

		StateRef& GetActiveState();
	private:
		std::stack<StateRef> _states;
		StateRef _newState;

		bool isRemoving;
		bool isAdding;
		bool isReplacing;

	};
}
//
