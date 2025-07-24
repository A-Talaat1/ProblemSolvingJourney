#include <optional>

template <typename type, std::size_t size>
constexpr std::optional<std::size_t> BinarySearch(const type (&data)[size], const type &target)
{
    // Initialize the start (first) and end (last) indices
    std::size_t first = 0;
    std::size_t last  = size - 1;
    std::size_t mid   = 0;  // Will store the middle index each iteration

    // Continue searching while the range is valid
    while (first <= last)
    {
        // Safe midpoint calculation to avoid integer overflow
        mid = first + ((last - first) / 2);

        // If the middle element is equal to the target, return its index
        if (data[mid] == target)
        {
            return mid;
        }
        else
        {
            // If the middle element is greater than the target,
            // search the left half (exclude mid)
            if (data[mid] > target)
            {
                last = mid - 1;
            }
            else
            {
                // Otherwise, search the right half (exclude mid)
                first = mid + 1;
            }
        }
    }

    // If the target is not found
    return std::nullopt;
}