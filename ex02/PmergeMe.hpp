/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:33:57 by faksouss          #+#    #+#             */
/*   Updated: 2023/11/23 09:50:00 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<iostream>
#include <stdexcept>
#include<string>
#include <sys/_types/_size_t.h>
#include<vector>
#include<deque>
#include<algorithm>

bool valid(std::string s);

template<typename T>

T PmergeMe(int ac, char **av){
    T cnt, tmp;
    int odd = -1;
    for (int i = 1; i < ac-(ac%2==0); i+=2){
        std::string f(av[i]), s(av[i+1]);
        if(!valid(f))
            throw(std::runtime_error("Error : Invalid argiment [" + f + "]"));
        else if (!valid(s))
            throw(std::runtime_error("Error : Invalid argiment [" + s + "]"));
        cnt.push_back(atoi(av[i]));
        cnt.push_back(atoi(av[i+1]));
        if (cnt[i-1] > cnt[i])
            std::swap(cnt[i-1], cnt[i]);
    }
    if (ac%2==0){
        if(!valid(av[ac-1])){
            std::string s(av[ac-1]);
            throw(std::runtime_error("Error : Invalid argiment [" + s + "]"));
        }
        odd = atoi(av[ac-1]);
    }
    for (size_t i = 0; i < cnt.size(); i+=2){
        for (int j=i+2; j >= 2 && j < (int)cnt.size(); j-=2){
            if (cnt[j] < cnt[j-2]){
                std::swap(cnt[j-2], cnt[j]);
                std::swap(cnt[j-1], cnt[j+1]);
            }
        }
    }
    for (size_t i = 1; i < cnt.size() && cnt.size() > 2; i++){
        tmp.push_back(cnt[i]);
        cnt.erase(cnt.begin()+i);
    }
    if (!tmp.empty())
        cnt.insert(std::lower_bound(cnt.begin(),cnt.end(),tmp[0]), tmp[0]);
    int a = 0, b = 1, c = b+(a*2), d = tmp.size();
    while (c < d){
        a = b;
        b = c;
        b+(a*2) >= d? c = d : c = b+(a*2);
        for (int i = c; i > b; i--)
            cnt.insert(std::lower_bound(cnt.begin(),cnt.end(),tmp[i-1]), tmp[i-1]);
    }
    if (odd != -1)
        cnt.insert(std::lower_bound(cnt.begin(),cnt.end(),odd), odd);
    return cnt;
}
