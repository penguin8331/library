#!/bin/sh

export $(cat .env| grep -v "#" | xargs)
export DROPBOX_TOKEN=$(
curl -s https://api.dropbox.com/oauth2/token \
-u ${DROPBOX_APP_KEY}:${DROPBOX_APP_SECRET} \
-d grant_type=refresh_token \
-d refresh_token=${DROPBOX_REFRESH_TOKEN} \
| jq -r '.access_token'
)
oj-verify all
