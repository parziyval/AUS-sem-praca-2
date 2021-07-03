#include <fstream>
#include <string>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include "unsorted_sequence_table.h"
#include "UzemnaJednotka.h"
#include "Stat.h"
#include "Obec.h"
#include "KriteriumUJNazov.h"
#include "Filter.h"
#include "FilterPodlaHodnoty.h"
#include "heap_monitor.h"
#include "Funkcionalita3.h"
#include "Funkcionalita4.h"
#include "Aplikacia.h"
int main() {
	initHeapMonitor();
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);

	Aplikacia app;
	app.spusti();
}