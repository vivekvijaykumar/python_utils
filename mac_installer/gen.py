#!/usr/bin/python

import base64
import os
import errno
import pkgutil
import sys
import tarfile
import pickle

prefix = "."
noprefix = ""
input_profile_files = [(prefix,'bash_profile'), (prefix, 'vimrc'), (prefix,'vim'),(noprefix,'scripts')]
output_profile_files = []

def usage():
    print "gen.py <argument>"
    print "argument can be 1) gen or 2) install"


#taken from the internet
def silentremove(filename):
    try:
        os.remove(filename)
    except OSError as e: # this would be "except OSError, e:" before Python 2.6
        if e.errno != errno.ENOENT: # errno.ENOENT = no such file or directory
            raise # re-raise exception if a different error occured


def make_tarfile(output_filename, source_dir):
    with tarfile.open(output_filename, "w") as tar:
        tar.add(source_dir, recursive=True, arcname=os.path.basename(source_dir))


def encode_profile_files():
    global profile_files,output_profile_files

    tempfile = "files_encoded.py"
    fout = open(tempfile,"wb")
    fout.write("#!/usr/bin/python")
    fout.write("\n\n\n")
    for pair in input_profile_files:
        prefix = pair[0]
        fname = pair[1]
        fname_with_path = str("/Users/vivvijay/") + prefix + fname

        if(os.path.isfile(fname_with_path) == False):
            fname = fname + "_tar"
            make_tarfile(fname,fname_with_path)
            fname_with_path = fname

        file_contents = open(fname_with_path,"rb").read()
        encoded_file  = base64.b64encode(file_contents)
        print "Generating encodings for %s of length %d"%(fname_with_path,len(encoded_file))
        fname = fname + "=\""
        fout.write(fname)
        fout.write(encoded_file)
        fout.write("\"\n\n\n")
        output_profile_files.append(fname_with_path)
        #output_profile_files.append([str(fname_with_path),encoded_file])

        if('tar' in fname_with_path):
            print "Cleaning up tmp files %s ..."%(fname_with_path)
            silentremove(fname_with_path)

    print "Total length of file %d "%(len(output_profile_files))
    #pickle.dump(output_profile_files,fout,-1)
    fout.write("output_profile_files=[" + str(output_profile_files) + "]")
    fout.close()


def decode_profile_files():
    global output_profile_files
    for fname in output_profile_files:
        print "decoding %s ..."%(fname)


def main():
    if (len(sys.argv) != 2):
        usage()
    elif (str(sys.argv[1]) == "gen"):
        encode_profile_files()
    elif (str(sys.argv[1]) == "install"):
        decode_profile_files()
    else:
        usage()

main()
#encode_profile_files()
#decode_profile_files()

