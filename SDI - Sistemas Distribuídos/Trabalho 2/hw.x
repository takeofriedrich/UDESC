struct envio {
	string data<>;
	string nome<>;
	string texto<>;
};

struct param {
	int arg1;
	int arg2;
};

program PROG {
	version VERS {
		int    func3(envio)  = 1;
	} = 1;
} = 0x30009999;
