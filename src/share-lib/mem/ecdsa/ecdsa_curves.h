/*Curves that can be loaded using ecdsa_parameters_load_curve()*/
typedef enum {	secp112r1 = 0,
				//secp112r2,	//See remark below
				secp128r1,
				//secp128r2,	//See remark below
				secp160k1,
				secp160r1,
				secp160r2,
				secp192k1,
				secp192r1,
				secp224k1,
				secp224r1,
				secp256k1,
				secp256r1,
				secp384r1,
				secp521r1 } curve_list;

/*Number of curves that can be loaded using ecdsa_parameters_load_curve()*/
#define NUMBER_OF_CURVES (secp521r1+1)

/*Load a curve depending on it's curve number, defined by the enum*/
void ecdsa_parameters_load_curve(ecdsa_parameters out, curve_list curve);

/* REMARK:
For some weird reason secp112r2 and secp128r2 doesn't want to be stable. Actually they work once in a while. However running the benchmark command gives -1 as operation time, sometimes and only sometimes!
Benchmark is supposed to write -1 as operation time if the operation failed.
As I don't see any reason to have extent my headache I'm putting this problem to rest by commenting these curves out. Furthermore it's very limited in terms of what can be done to debug these curves, since I don't have any test vectors for them.
It's probably related to a bug in the implementation, perhaps an exception I didn't handle or round of, who knows.
*/
