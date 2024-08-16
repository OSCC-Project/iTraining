#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<vector>
#include<memory>

struct Review
{
    std::string title;
    int rating;
    double price;

    Review(std::string s, int r, double p):title(s),rating(r),price(p){

    }
};

bool operator<(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool ratingWorseThan(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool ratingBetterThan(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool priceWorseThan(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool priceBetterThan(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool FillReview(std::shared_ptr<Review>& rr);
void ShowReview(const std::shared_ptr<Review> rr);

int main(int argc, char** argv){
    
    std::vector<std::shared_ptr<Review>> books;
    std::shared_ptr<Review> temp;
    while(FillReview(temp)){
        books.push_back(temp);
    }
    if(books.size() > 0){
        std::cout << "Enter a number to select books displayed(0:quit, 1:raw, 2:AlphaBetical, 3:rating ascend, 4:rating descend, 5:price ascend, 6:price descend): ";
        enum {QUIT, RAW, AB, RA, RD, PA, PD};
        int display;
        while(std::cin >> display){
            if(display == 0){
                break;
            }
            switch (display)
            {
            case RAW:
                std::cout << "Thank you. You entered the following " << books.size() << " books:\n" << "Rating\tPrice\tBook\n";
                std::for_each(books.begin(), books.end(), ShowReview);
                break;
            case AB:
                std::sort(books.begin(), books.end());
                std::cout << "Sorted by title:\nRating\tPrice\tBook\n";
                std::for_each(books.begin(), books.end(), ShowReview);
                break;
            case RA:
                std::sort(books.begin(), books.end(), ratingWorseThan);
                std::cout << "Sorted by rating in ascending order:\nRating\tPrice\tBook\n";
                std::for_each(books.begin(), books.end(), ShowReview);
                break;
            case RD:
                std::sort(books.begin(), books.end(), ratingBetterThan);
                std::cout << "Sorted by rating in descending order:\nRating\tPrice\tBook\n";
                std::for_each(books.begin(), books.end(), ShowReview);
                break;
            case PA:
                std::sort(books.begin(), books.end(), priceWorseThan);
                std::cout << "Sorted by rating in ascending order:\nRating\tPrice\tBook\n";
                std::for_each(books.begin(), books.end(), ShowReview);
                break;
            case PD:
                std::sort(books.begin(), books.end(), priceBetterThan);
                std::cout << "Sorted by rating in descending order:\nRating\tPrice\tBook\n";
                std::for_each(books.begin(), books.end(), ShowReview);
                break;
            default:
                break;
            }
            std::cout << "Enter a number to select books displayed(0:quit, 1:raw, 2:AlphaBetical, 3:rating ascend, 4:rating descend, 5:price ascend, 6:price descend): ";
        }
    }
    else{
        std::cout << "No entries. ";
    }
    std::cout << "Bye.\n";

    return 0;
}

// bool operator<(const Review& r1, const Review& r2){
//     if(r1.title < r2.title){
//         return true;
//     }
//     else if (r1.title == r2.title && r1.rating < r2.rating){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

bool operator<(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2){
    if(r1->title < r2->title){
        return true;
    }
    else if (r1->title == r2->title){
        if(r1->rating == r2->rating && r1->price > r2->price){
            return true;
        }
        else if(r1->rating < r2->rating){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool ratingWorseThan(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2){
    if (r1->rating < r2->rating){
        return true;
    }
    else{
        return false;
    }
}
bool ratingBetterThan(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2){
    if (r1->rating > r2->rating){
        return true;
    }
    else{
        return false;
    }
}
bool priceWorseThan(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2){
    if (r1->price < r2->price){
        return true;
    }
    else{
        return false;
    }
}
bool priceBetterThan(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2){
    if (r1->price > r2->price){
        return true;
    }
    else{
        return false;
    }
}

bool FillReview(std::shared_ptr<Review>& rr){
    std::cout << "Enter book title(quit to quit): ";
    std::string title;
    int rating;
    double price;

    std::getline(std::cin, title);
    if(title == "quit"){
        return false;
    }
    std::cout << "Enter book rating: ";
    std::cin >> rating;
    std::cout << "Enter book price: ";
    std::cin >> price;
    if(!std::cin){
        return false;
    }
    while(std::cin.get() != '\n'){
        continue;
    }

    rr = std::make_shared<Review>(title, rating, price);

    return true;
}

void ShowReview(const std::shared_ptr<Review> rr){
    std::cout << rr->rating << "\t" << rr->price << "\t" << rr->title << std::endl;
}

