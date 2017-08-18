# eventManager
c++ Publish/Subscribe event system 

demo here:
void test()
{
	Observed sys;

	OA a;
	OB b;
	OC c;

	sys.addObserver(&a, Event_A);
	sys.addObserver(&a, Event_B);

	sys.addObserver(&b, Event_A);
	sys.addObserver(&c, Event_A);

	AEvent aevent;
	std::cout << ("1 sendEvent Event_A") << std::endl;
 
	sys.sendEvent(&aevent);

	std::cout << ("2 OA removeObserver Event_A") << std::endl;
	sys.removeObserver(&a, Event_A);
	AEvent aevent1;
	std::cout << ("  sendEvent Event_A") << std::endl;
	 
	sys.sendEvent(&aevent1);
}
