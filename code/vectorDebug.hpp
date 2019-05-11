/* * * * * * * * * * * * * *
 * * * vectorDebug.hpp * * *
 * * * * * * * * * * * * * */ 
#ifndef _VECTOR_DEBUG_
#define _VECTOR_DEBUG_
	#include <iostream>
	// #define DEBUG
	class VectorDebug {
		public:
			VectorDebug() {}
			virtual void ErrMsg() const {
				std::cerr << "Error with Vect object.\n";
			}
			void Continue() const {
				#ifdef DEBUG
					std::cerr << "Debug: program is being continued.\n";
				#else
					throw;
				#endif
			}
		};

		class VectRangeErr : public VectorDebug {
		public:
			VectRangeErr(int _min, int _max, int _actual) :
						  min(_min), max(_max), actual(_actual) {}
			void ErrMsg() const {
				std::cerr << "Error of index: ";
				std::cerr << "possible range: " << min << " - " << max << ", ";
				std::cerr << "actual index: " << actual << std::endl;
				Continue();
			}

		private:
			int min, max;
			int actual;
		};

		class VectPopErr : public VectorDebug {
			public:
				void ErrMsg() const {
					std::cerr << "Error of pop\n";
					Continue();
				}
	};
#endif /* _VECTOR_DEBUG_ */
/* * * * * * * * * * * * */ 