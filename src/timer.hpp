namespace aw109::rtu
{
    template <int TimerMs>
    class Timer
    {
    private:
        bool first = true;
        int start_millis = 0;
        int current_millis = 0;

    public:
        void tick(int ms)
        {
            if (first)
            {
                start_millis = ms;
                first = false;
            }
            current_millis = ms;
        }

        bool is_expired() const
        {
            return current_millis > start_millis + TimerMs;
        }

        void reset()
        {
            first = true;
        }
    };
} // namespace aw109::rtu
