/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 01:58:54 by faksouss          #+#    #+#             */
/*   Updated: 2023/11/21 04:47:41 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <fstream>
#include<iostream>
#include <ostream>
#include<string>
#include<map>
#include<sstream>

/*************************************[TIME]*****************************************/

typedef struct Time{
    unsigned int d;//Day
    unsigned int m;//Month
    unsigned int y;//Year
    
    /*         [Time Constructors]         */
    Time(unsigned int y, unsigned int m, unsigned d);
    Time( void );
    /*************************************/

    /*         [(=) Operator Overload]         */
    Time &operator=( const Time &date );
    /*******************************************/
    
    /*         [Comperation Operators Overload]         */
    bool operator>( const Time &a ) const ;
    bool operator<( const Time &a ) const ;
    bool operator>=( const Time &a ) const ;
    bool operator<=( const Time &a ) const ;
    bool operator==( const Time &a ) const ;
    bool operator!=( const Time &a ) const ;
    /***************************************************/

    /*         [Time Out Of Range Error]         */
    class timeError : public std::exception{
        public:
            virtual const char *what() const throw();
    };
    /*********************************************/
} Time;
/*************************************************************************************/

typedef std::map<Time, float> MAP;

/*******************************[BITCOINEXCHANGE]************************************/
class BitcoinExchange{
    private:
        MAP dataBase;//DataBase
    public:
        /*[BitcoinExchange Constructors & Deconstrucot]*/
        BitcoinExchange( void );
        BitcoinExchange( MAP &dataBase );
        BitcoinExchange( const BitcoinExchange &obj );
        ~BitcoinExchange( void );
        /************************************************/
        /*         [(=) Operator Overload]         */
        BitcoinExchange &operator=( const BitcoinExchange &obj );
        /*******************************************/
        /*        [Geters & Seters]        */
        void setDataBase( MAP &dataBase );
        MAP getDataBase( void ) const;
        /***********************************/
        /*     [Reading & Exchanging Bitcoin Value]    */
        void exchangeBitcoin( std::ifstream &input );
        /***********************************************/
};
/************************************************************************************/


/*     [Overload Of the insertion Operator(<<)]      */
std::ostream &operator<<( std::ostream &out, Time &tm );
/*****************************************************/

/*         [Helper Functions]         */
/*
    Read the database file line by line checking
    if it is valid and storing it in a map to search
    in it later
*/
MAP readDataFile( std::ifstream &file );

/*
    Take a line checking if it is valide converting it
    to the needed type to stor it in a pair to add it to
    the data base map
*/
std::pair<Time, float> getDataPair( std::string &line );

/*
    Helper function to parss the line checking if the format is valid
    and filling the needed data to work with and returning true otherwise
    returns false and printing an error discribing what happend
*/
bool checkLine(std::string &line, std::string *d, std::string &v, int c);
/**************************************/
