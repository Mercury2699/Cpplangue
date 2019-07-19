#!/bin/bash

subroutine(){
  echo $1
  echo ${1%00}
}

subroutine $(($1 * 1000))
