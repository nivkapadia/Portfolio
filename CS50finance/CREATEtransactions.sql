CREATE TABLE transactions
(
    transaction_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    id  INTEGER NOT NULL,
    symbol TEXT NOT NULL,
    buy_price INTEGER NOT NULL,
    FOREIGN KEY (id) REFERENCES users(id)
)
