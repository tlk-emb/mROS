#ifndef _MROS_TEST_PERSONALDATA_H
#define _MROS_TEST_PERSONALDATA_H




static const int PERSONALDATA_MSG_ID = 101;

namespace mros_test{
class PersonalData{
public:
  float floatVal;
  double doubleVal;
  uint8_t boolVal;

  int dataSize(){
    return  4 +  8 +  1 +  4*0;
  }

  void memCopy(char*& addrPtr){
    int size; 
    
    memcpy(addrPtr,&floatVal,4);
    addrPtr += 4;
    
    memcpy(addrPtr,&doubleVal,8);
    addrPtr += 8;
    
    memcpy(addrPtr,&boolVal,1);
    addrPtr += 1;
    
  }

  void deserialize(char*& rbuf){
    uint32_t size;
    memcpy(&floatVal,rbuf,4);
    rbuf += 4;
    
    memcpy(&doubleVal,rbuf,8);
    rbuf += 8;
    
    memcpy(&boolVal,rbuf,1);
    rbuf += 1;
    
    
  }
};

}

namespace message_traits
{
template<>
struct MD5Sum<PERSONALDATA_MSG_ID>
{
  static const char* value()
  {
    return "e786a9d71f124a2deaedd6ee32a2af2a";
  }

};

template<>
struct DataType<mros_test::PersonalData*>
{
  static const char* value()
  {
    return "mros_test/PersonalData";
  }

};

template<>
struct DataTypeId<mros_test::PersonalData*>
{
  static const int value()
  {
    return PERSONALDATA_MSG_ID;
  }

};

template<>
struct Definition<mros_test::PersonalData*>
{
	static const char* value()
	{
		return "float32 floatVal\n\
float64 doubleVal\n\
bool boolVal\n\
";
	}
};
}

namespace subtask_methods
{
  template<>
  struct CallCallbackFuncs<PERSONALDATA_MSG_ID>{
    static void call(void (*fp)(intptr_t), char *rbuf)
    {
      mros_test::PersonalData msg;
      rbuf += 4;
      msg.deserialize(rbuf);
      fp(&msg);
    }
  };
}

#endif