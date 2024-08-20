-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND activity = 'exit' AND hour = 10 AND minute > 14 and minute < 26);
SELECT name FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE atm_location = 'Leggett Street' AND day = 28 AND month = 7 AND year = 2021 AND transaction_type = 'withdraw'));\
SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE duration < 60 AND day = 28 AND month = 7);
SELECT name FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE full_name LIKE '%fiftyville%') AND day = 29 AND month = 7 ORDER BY hour LIMIT 1));
SELECT id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE full_name LIKE '%fiftyville%') AND day = 29 AND month = 7 ORDER BY hour LIMIT 1;
SELECT name FROM people WHERE phone_number = (SELECT receiver FROM phone_calls WHERE phone_number = (SELECT phone_number FROM people WHERE name = 'Bruce') AND day = 28 AND month = 7 AND duration < 60);

