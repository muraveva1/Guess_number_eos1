#include <eosiolib/eosio.hpp>
#include <guess_number.hpp>

using namespace eosio;


namespace guess_number {

struct impl{
	
	
	
	
	void apply(uint64_t receiver, uint64_t code, uint64_t action) {
		
		if (code==code_account){
			if (action == N(create)) {
				impl::on(eosio::unpack_action_data<guess_number>());
			} else if (action == N(close)){
				impl::on(eosio::unpack_action_data<guess_number::close>());
			} else if (action == N(move)) {
				impl::on(eosio::unpack_action_data<guess_number::move>());
			}
		}
	};
	}
	
	extern "C" {

   using namespace tic_tac_toe;
   /// The apply method implements the dispatch of events to this contract
   void apply( uint64_t receiver, uint64_t code, uint64_t action ) {
      impl().apply(receiver, code, action);
   }
}
