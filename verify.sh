#!/bin/bash

export $(cat .env| grep -v "#" | xargs)
oj-verify all
