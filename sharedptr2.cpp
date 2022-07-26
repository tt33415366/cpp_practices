#include <string>
#include <fstream> // for ofstream
#include <memory> // for shared_ptr
#include <cstdio> // for remove()

#include <thread> // std::this_thread::sleep_for
#include <chrono> // std::chrono::seconds
class FileDeleter
{
	private:
		std::string filename;

	public:
		FileDeleter (const std::string& fn)
			: filename(fn) {}
		void operator () (std::ofstream* fp) {
			fp->close();   // close.file
			std::remove(filename.c_str()); // delete file
		}
};

int main()
{
	// create and open temporary file:
	std::shared_ptr<std::ofstream> fp(new std::ofstream("tmpfile.txt"),
			FileDeleter("tmpfile.txt"));
	*fp << "Hello shared_ptr and custom deleter" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
}
