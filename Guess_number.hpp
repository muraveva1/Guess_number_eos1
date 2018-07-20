#include <eosiolib/eosio.hpp>


using namespace eosio;
namespace guess_number {
	static const account_name games_account = N(games);
	static const account_name code_account = N(guess_number);
	
	
	struct game{
		game() {}
		game(account_name challenger, account_name host):challenger(challenger), host(host), turn(host);
		account_name   challenger;
		account_name   host;
		account_name   turn;
		account_name   winner = N(none);
		
		auto primary_key() const { return challenger; }

      EOSLIB_SERIALIZE( game, (challenger)(host)(turn)(winner) )
   };
   
   
    struct create {
      account_name   challenger;
      account_name   host;

      EOSLIB_SERIALIZE( create, (challenger)(host) )
   };

struct close {
      account_name   challenger;
      account_name   host;

      EOSLIB_SERIALIZE( close, (challenger)(host) )
   };
   
   
      struct move {
      account_name   challenger;
      account_name   host;
      account_name   by; // the account who wants to make the move
      

      EOSLIB_SERIALIZE( move, (challenger)(host)(by) )
   };
	
	
	typedef eosio::multi_index< games_account, game> games;
	}


