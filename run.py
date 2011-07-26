#!/usr/bin/python

import subprocess
import json
import sys

problems = {
	'1': {"number": 1, "python": "python/Problem001.py", "c": "c/Problem001.c", "answer": 233168},
	'2': {"number": 2, "python": "python/Problem002.py", "c": "c/Problem002.c", "answer": 4613732},
	'3': {"number": 3, "python": "python/Problem003.py", "c": "c/Problem003.c", "answer": 6857},
	'4': {"number": 4, "python": "python/Problem004.py", "c": "c/Problem004.c", "answer": 906609},
	'5': {"number": 5, "python": "python/Problem005.py", "c": "c/Problem005.c", "answer": 232792560},
	'6': {"number": 6, "python": "python/Problem006.py", "c": "c/Problem006.c", "answer": 25164150},
	'7': {"number": 7, "python": "python/Problem007.py", "c": "c/Problem007.c", "answer": 104743},
	'8': {"number": 8, "python": "python/Problem008.py", "c": "c/Problem008.c", "answer": 40824},
	'9': {"number": 9, "python": "python/Problem009.py", "c": "c/Problem009.c", "answer": 31875000},
	'10': {"number": 10, "python": "python/Problem010.py", "c": "c/Problem010.c", "answer": 142913828922},
	'11': {"number": 11, "python": "python/Problem011.py", "c": "c/Problem011.c", "answer": 70600674},
	'12': {"number": 12, "python": "python/Problem012.py", "c": "c/Problem012.c", "answer": 76576500},
	'13': {"number": 13, "python": "python/Problem013.py", "c": "c/Problem013.c", "answer": 5537376230},
	'14': {"number": 14, "python": "python/Problem014.py", "c": "c/Problem014.c", "answer": 837799},
	'15': {"number": 15, "python": "python/Problem015.py", "c": "c/Problem015.c", "answer": 137846528820},
	'16': {"number": 16, "python": "python/Problem016.py", "c": "c/Problem016.c", "answer": 1366},
	'17': {"number": 17, "python": "python/Problem017.py", "c": "c/Problem017.c", "answer": 21124},
	'18': {"number": 18, "python": "python/Problem018.py", "c": "c/Problem018.c", "answer": 1074},
	'19': {"number": 19, "python": "python/Problem019.py", "c": "c/Problem019.c", "answer": 171},
	'20': {"number": 20, "python": "python/Problem020.py", "c": "c/Problem020.c", "answer": 648},
	'21': {"number": 21, "python": "python/Problem021.py", "c": "c/Problem021.c", "answer": 31626},
	'22': {"number": 22, "python": "python/Problem022.py", "c": "c/Problem022.c", "answer": 871198282},
	'23': {"number": 23, "python": "python/Problem023.py", "c": "c/Problem023.c", "answer": 4179871},
	'24': {"number": 24, "python": "python/Problem024.py", "c": "c/Problem024.c", "answer": 2783915460},
	'25': {"number": 25, "python": "python/Problem025.py", "c": "c/Problem025.c", "answer": 4782},
	'28': {"number": 28, "python": "python/Problem028.py", "c": "c/Problem028.c", "answer": 669171001},
	'48': {"number": 48, "python": "python/Problem048.py", "c": "c/Problem048.c", "answer": 9110846700},
	'67': {"number": 67, "python": "python/Problem067.py", "c": "c/Problem067.c", "answer": 7273}
}

def runPython(file):
	
	command = ['/usr/bin/time', '-f',  """{"memory":"%M","time":"%e","exit":"%x"}""", 'python', file]
	
	(stdout_data, stderr_data) = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE).communicate()
	try:
		result = stdout_data.strip().replace("Answer: ", '')
		
		stats = json.loads(stderr_data.strip())
		
		if int(stats['exit']) != 0:
			raise Exception("Non-Zero return code returned")
		
		return {'result': result, 'stats': stats}
	except Exception as e:
		print e
		return False

def runC(file):
	
	retcode = subprocess.Popen(['gcc', file, '-o', 'a.out'], stdout=subprocess.PIPE, stderr=subprocess.PIPE).wait()
	
	try:
		if retcode != 0:
			raise Exception("Error compiling")
		
		command = ['/usr/bin/time', '-f',  '{\"memory\":\"%M\",\"time\":\"%e\",\"exit\":\"%x\"}', './a.out']
		
		(stdout_data, stderr_data) = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE).communicate()
		result = stdout_data.strip().replace("Answer: ", '')
		
		stats = json.loads(stderr_data.strip())
		
		if int(stats['exit']) != 0:
			return False
		
		subprocess.Popen(['rm', 'a.out'], stdout=subprocess.PIPE, stderr=subprocess.PIPE).wait()
		
		return {'result': result, 'stats': stats}
	except Exception as e:
		print e
		return False
	
def formatResult(language, problem, result):
	
	problem_number = problem['number']
	expected_answer = problem['answer']
	if result == False:
		answer = 0
		time = 0.0
		memory = 0
		status = "ERROR"
	else:
		answer = int(result['result'])
		time = float(result['stats']['time'])
		memory = int(result['stats']['memory'])
		
		if answer == expected_answer:
			status = "PASSED"
		else:
			status = "FAILED"
	
	
	result =  "    +--------------------------------------------+\n"
	result += "    | Project Euler     Problem {:03d}       {:>6s} |\n".format(problem_number, status)
	result += "    +--------------------------------------------+\n"
	result += "    |            Language:  {:>20s} |\n".format(language)
	result += "    |     Expected Answer:  {:>20d} |\n".format(expected_answer)
	result += "    |   Calculated Answer:  {:>20d} |\n".format(answer)
	result += "    |        Running Time:  {:>18.4f} s |\n".format(time)
	result += "    |        Memory Usage:  {:>17d} kB |\n".format(memory)
	result += "    +--------------------------------------------+\n"
	
	return result

def runProblem(problem):
	
	result = runPython(problem['python'])
	
	formatted = formatResult('python', problem, result)
	
	print formatted
	
	file = open('reports/python/Problem{:03d}.md'.format(problem['number']), 'w')
	file.write(formatted)
	file.close()
	
	result = runC(problem['c'])
	formatted = formatResult('c', problem, result)

	print formatted
	
	file = open('reports/c/Problem{:03d}.md'.format(problem['number']), 'w')
	file.write(formatted)
	file.close()
	
if len(sys.argv) == 2:
	question = sys.argv[1]
	runProblem(problems[question])
else:
	for problem in problems:
		runProblem(problems[problem])


