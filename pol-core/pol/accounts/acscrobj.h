/*
History
=======
2009/12/21 Turley:    ._method() call fix


Notes
=======

*/

#ifndef ACSCROBJ_H
#define ACSCROBJ_H

#include "../reftypes.h"

#ifndef BSCRIPT_BOBJECT_H
#include "../../bscript/bobject.h"
#endif

namespace Pol {
  namespace Accounts {
	class AccountPtrHolder
	{
	public:
	  explicit AccountPtrHolder( Core::AccountRef i_acct ) : acct( i_acct ) {}
	  Account* operator->( ) { return acct.get(); }
	  const Account* operator->( ) const { return acct.get(); }

	  Account* Ptr() { return acct.get(); }
	private:
	  Core::AccountRef acct;
	};

	extern Bscript::BApplicObjType accountobjimp_type;
	class AccountObjImp : public Bscript::BApplicObj< AccountPtrHolder >
	{
	  typedef Bscript::BApplicObj< AccountPtrHolder > base;
	public:
	  explicit AccountObjImp( const AccountPtrHolder& other ) :
		Bscript::BApplicObj< AccountPtrHolder >( &accountobjimp_type, other )
	  {}
	  virtual const char* typeOf() const POL_OVERRIDE;
	  virtual int typeOfInt() const POL_OVERRIDE;
	  virtual Bscript::BObjectImp* copy( ) const POL_OVERRIDE;
	  virtual Bscript::BObjectImp* call_method( const char* methodname, Bscript::Executor& ex ) POL_OVERRIDE;
	  virtual Bscript::BObjectImp* call_method_id( const int id, Bscript::Executor& ex, bool forcebuiltin = false ) POL_OVERRIDE;
	  virtual Bscript::BObjectRef get_member( const char* membername ) POL_OVERRIDE;
	  virtual Bscript::BObjectRef get_member_id( const int id ) POL_OVERRIDE; //id test
	};

  }
}
#endif
