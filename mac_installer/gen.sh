#!/bin/bash

profile_generate()
{
    out='setup.py'
    in1='files_encoded.py'
    in2='gen.py'

    rm $out
    ./gen.py "gen"

    if [ -e $in1 ] && [ -e $in2 ] ; then
        echo "Generating setup installer .... "
        cat files_encoded.py >> $out 
        echo -e "" >> $out
        cat gen.py >> $out
        chmod 775 $out
    fi
    echo -e "Profiles generated ... "
}

profile_installer() 
{
    ./setup.py "install"
}

homebrew_install()
{
    ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
}

xcode_install()
{
    #Xcode installer needed for homebrew
    xcode_version_string=`xcode-select --version`
    xcode_version=`echo $xcode_version_string | cut -d' ' -f3 | cut -d'.' -f1`
    if [ $xcode_version -ge 2333 ]; then
        echo "Installing xcode command line tools for mac ..."
       ret=` xcode-select --install`
    else
        echo -e "xcode-select has old version $xcode_version_string"
        echo -e "Upgrade xcode-select before proceeding ... "
        return 0
    fi

    return $ret
}

brew_install_formula()
{
    case "$1" in
        "wget") brew install wget;;
    esac
}

# Run the package installer commands
mac_cli_package_installer() 
{

    echo -e "Installing xcode cli tools ... "
    xcode_install
     if [ $? -eq 0 ]; then
        echo -e "Successfully installed xcode cli tools ..."
    else 
        echo -e "Xcode-cli installtion failed with $?"
    fi

    #homebrew installation
    echo -e "Installing homebrew ..."
    homebrew_install
    if [ $? -eq 0 ]; then
        echo -e "Successfully installed homebrew ..."
    else 
        echo -e "Homebrew installtion failed with $?"
    fi

    #brew install wget
    brew_install_formula "wget"
     if [ $? -eq 0 ]; then
        echo -e "Successfully installed wget ..."
    else 
        echo -e "wget installtion failed with $?"
    fi
}

# Run the python installer to install the profile files
main()
{
    case $1 in 
        1)
            profile_generate
            ;;
        2)  
            profile_installer
            ;;
        *) 
            echo -e "Wrong argument"
            exit
            ;;
    esac
}

main $1 

#install the mac_cli_package_installer while install option is chosen
if [ $1 -eq 2 ]; then
    if [ $? -eq 0 ]; then
        mac_cli_package_installer
    fi
fi

echo -e "Completed!!! "
