#include "StateMachine.h"

namespace MathWars {
	void StateMachine::AddState(StateRef newState, bool isReplacing){
		this->isAdding = true;
		this->isReplacing = isReplacing;

		this->_newState = std::move(newState);
	}

	void StateMachine::RemoveState(){
		this->isRemoving = true;
	}

	void StateMachine::ProcessStateChanges(){
		if (this->isRemoving && !this->_states.empty()){
			this->_states.pop();

			if (!this->_states.empty()){
				this->_states.top()->Resume();
			}

			this->isRemoving = false;
		}

		if (this->isAdding){
			if (!this->_states.empty()){
				if (this->isReplacing){
					this->_states.pop();
				}
				else{
					this->_states.top()->Pause();
				}
			}

			this->_states.push(std::move(this->_newState));
			this->_states.top()->Init();
			this->isAdding = false;
		}
	}

	StateRef& StateMachine::GetActiveState(){
		return this->_states.top();
	}
}
//