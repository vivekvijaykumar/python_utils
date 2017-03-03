#!/usr/bin/python


import os,time,threading, sys, getopt
from glob import glob
from itertools import chain

import threading

result_list = []
result_list_flat = []

filesPerThread = 50
threadCount = 0
filesPerThreadList = []
dryRun = False

# thread objects list
threads = []

target=""

def work(myid, count, start):
    global result_list_flat, dryRun, target
    files = result_list_flat[start:start+count]
    for file in files:
        if not file:
            continue
        try:
            properties = os.stat(file)
        except:
            print "[%d] %s ::: stat error: %s"%(myid, file, str(sys.exc_info()))
            sys.exit()

        timestamp = time.strftime("%Y-%m-%d_%H-%M-%S", time.gmtime(properties.st_mtime))

        only = file.split("/")[len(file.split("/"))-1]

        newfile = target + str(timestamp) + "_" + only
        print "[%d] Renaming %s to %s"%(myid, file,newfile)
        if dryRun == False:
            try:
                os.rename(file, newfile)
            except:
                print "[%d] %s ::: move error: %s" % (myid, file, str(sys.exc_info()))


def createThread():
    global  filesPerThread, threadCount, filesPerThreadList, threads, dryRun
    start = 0
    myid = 0
    count = threadCount
    for i in xrange(count):
        try:
            t = threading.Thread(target=work, args=(myid, filesPerThreadList[i], start, ))
            start += filesPerThreadList[i]
            myid += 1
            threads.append(t)
        except:
            print "Thread creation failed: " , sys.exc_info()[0]


def runThread():
    global threads

    for t in threads:
        t.start()


def main():
    global result_list, result_list_flat, filesPerThread, threadCount, filesPerThreadList, dryRun, target
    path = ""

    try:
        opts, args = getopt.getopt(sys.argv[1:], "dhi:o:",["input=", "output="])
    except getopt.GetoptError:
        print "Error: ", sys.exc_info()
        assert False, "Bad input"
        #print "rename.py -p <path to target folder>"

    for opt, arg in opts:
        if opt in ("-h", "--help"):
            print "rename.py -i <path to input folder> -o <path to target folder>"
            sys.exit()
        elif opt in ("-d", "--dryrun"):
            print "dry run"
            dryRun = True
        elif opt in ("-i", "--input"):
            path = arg
        elif opt in ("-o", "--output"):
            target = arg
        else:
            print "Wrong arguments. run 'rename.py -h' for more info... "
            sys.exit()

    '''
        generator is better as they are move space efficient. not sure how to use them
        with threading model to split the inputs to different threads.

        use a static list instead
    '''
    # result = (chain.from_iterable(glob(os.path.join(x[0], '*.*')) for x in os.walk('.')))
    result_list = [glob(os.path.join(x[0], '*.*')) for x in os.walk(path)]
    result_list_flat = [item for sublist in result_list for item in sublist]

    filesPerThread = 50
    threadCount = len(result_list_flat) / filesPerThread
    filesPerThreadList = [50] * threadCount
    val = len(result_list_flat) % filesPerThread
    filesPerThreadList[-1] +=  val

    createThread()
    runThread()


main()
